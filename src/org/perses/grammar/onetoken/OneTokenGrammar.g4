grammar OneTokenGrammar;

TOKEN
    : .+
    ;

wholeFile
    : TOKEN EOF
    ;