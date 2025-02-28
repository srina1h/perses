#! /bin/bash

TIMEOUT=30

GOOD_VERSION="1e9bc83"
BAD_VERSION="816b386"

if [ -z "${XML_JAR_DIR}" ]; then
  echo "Error: XML_JAR_DIR is not set."
  exit 1
fi

QUERY='declare namespace Aa ="saEqczELwiDr";declare namespace eTA ="NrJTEVj";declare namespace A ="xBgwTrJDHDdbRMXBx";declare namespace ycMC ="iFMLJyyqIYnZTtwzRjQf";declare namespace feMuH ="WyfHLLUDdrTuJjNxgxH";declare namespace VrN ="X";declare namespace CrEt ="iF";declare namespace EU ="fLxguhNPLNhmUoaCLj";declare namespace yAcX ="QcMEgKoMhEpBY";declare namespace CIIz ="NrJTEVj";declare namespace s ="xBgwTrJDHDdbRMXBx";declare namespace ibfTi ="saEqczELwiDr";//*/ancestor::*[reverse(boolean(reverse(B29))) or not(boolean(normalize-space(@e9)))]/CIIz:G5/preceding::VrN:U5[not((boolean(tail(./(/U13/S11/E16/F5/T6/H7/U5))) and false()) ! head(.))]/parent::*[(boolean(last()) or ((head(head(head(head(subsequence(., 2))/node-name()))) ! .) castable as xs:duration)) or (reverse(boolean(.)) = false()) = false()]/Aa:T31[boolean((node-name() ! count(subsequence(., 90))) + -299134339) and (boolean(last()) and not(boolean(subsequence(tail(./preceding-sibling::Aa:E3), 2))))]/parent::VrN:H7[boolean(./*//*[not(boolean(O31))])]/*'
echo $QUERY > query.xq

# run reference
reference="saxon"
timeout -s 9 $TIMEOUT java -cp "${XML_JAR_DIR}/saxon-he-12.4.jar:${XML_JAR_DIR}/xmlresolver-5.2.0.jar" \
  net.sf.saxon.Query -s:./input.xml -q:./query.xq > ${reference}_raw_result.xml 2>&1
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

# run basex_bad
target_basex_bad="basex_bad"
timeout -s 9 $TIMEOUT java -cp "${XML_JAR_DIR}/basex-${BAD_VERSION}.jar" \
  org.basex.BaseX -i input.xml query.xq > ${target_basex_bad}_raw_result.xml 2>&1
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

# run basex_good
target_basex_good="basex_good"
timeout -s 9 $TIMEOUT java -cp "${XML_JAR_DIR}/basex-${GOOD_VERSION}.jar" \
  org.basex.BaseX -i input.xml query.xq > ${target_basex_good}_raw_result.xml 2>&1
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

# process saxon result
grep -o 'id="[^"]*"' ${reference}_raw_result.xml | \
  grep -v '^[[:space:]]*$' > ${reference}_processed_result.txt

# process basex_bad result
grep -o 'id="[^"]*"' ${target_basex_bad}_raw_result.xml | \
  grep -v '^[[:space:]]*$' > ${target_basex_bad}_processed_result.txt

# process basex_good result
grep -o 'id="[^"]*"' ${target_basex_good}_raw_result.xml | \
  grep -v '^[[:space:]]*$' > ${target_basex_good}_processed_result.txt


# the output of bad basex version should be different from the output of reference
if diff ${reference}_processed_result.txt ${target_basex_bad}_processed_result.txt > /dev/null 2>&1; then
    exit 1
fi

# the output of good basex version should be the same as the output of reference
if ! diff ${reference}_processed_result.txt ${target_basex_good}_processed_result.txt > /dev/null 2>&1; then
    exit 1
fi

exit 0


