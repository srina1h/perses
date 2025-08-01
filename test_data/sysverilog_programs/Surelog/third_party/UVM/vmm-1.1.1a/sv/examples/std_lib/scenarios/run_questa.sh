#!/bin/sh

if [ -z "$VMM_HOME" ]; then
  VMM_HOME=../../../..
fi

if [ -z "$VMM_DPI_DIR" ]; then
  VMM_DPI_DIR=$VMM_HOME/shared/lib/linux_x86_64
fi

if [ "$1" = clean ]; then
  rm -rf *.log *.log.filtered *.wlf transcript* work
  exit
fi

vlib work
vlog -mfcu -sv +incdir+$VMM_HOME/sv+. test.sv | tee test.log
if [ $? -eq 0 ]; then
  vsim -c -do "set SolveArrayResizeMax 5000; run -all; quit" \
    -sv_lib $VMM_DPI_DIR/vmm_str_dpi test -l test.log
fi

# internal use only
EX=$VMM_HOME/sv/examples
FILTER_EXTRA="\$file =~ s/addr=.h[0-9a-f]+/addr=VAL/g; \
              \$file =~ s/data=.h[0-9a-f]+/data=VAL/g; "
if [ -n "$INTEROP_REGRESS" ]; then
  perl $EX/regress/regress_compare_gold.pl ref/test.log test.log "std_lib/scenarios" "$FILTER_EXTRA" $EX/results.log
fi
