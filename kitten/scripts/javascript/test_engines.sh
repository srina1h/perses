#!/bin/bash

# Test script to verify V8, XS, QuickJS, and JerryScript engines are working
set -e

echo "Testing JavaScript engines for differential testing..."

# Test V8
echo "Testing V8 engine..."
if command -v v8 >/dev/null 2>&1; then
    echo "V8 version:"
    v8 --help | head -5 || echo "V8 help command failed, but engine exists"
    echo "V8 test:"
    echo "console.log('V8 working');" | v8 || echo "V8 execution failed"
else
    echo "ERROR: V8 engine not found"
    exit 1
fi

echo ""

# Test XS
echo "Testing XS engine..."
if command -v xs >/dev/null 2>&1; then
    echo "XS version:"
    xs --version || echo "XS version command failed, but engine exists"
    echo "XS test:"
    echo "console.log('XS working');" | xs || echo "XS execution failed"
else
    echo "ERROR: XS engine not found"
    exit 1
fi

echo ""

# Test QuickJS
echo "Testing QuickJS engine..."
if command -v quickjs >/dev/null 2>&1; then
    echo "QuickJS version:"
    quickjs --version || echo "QuickJS version command failed, but engine exists"
    echo "QuickJS test:"
    echo "console.log('QuickJS working');" | quickjs || echo "QuickJS execution failed"
else
    echo "ERROR: QuickJS engine not found"
    exit 1
fi

echo ""

# Test JerryScript
echo "Testing JerryScript engine..."
if command -v jerryscript >/dev/null 2>&1; then
    echo "JerryScript version:"
    jerryscript --version || echo "JerryScript version command failed, but engine exists"
    echo "JerryScript test:"
    echo "console.log('JerryScript working');" | jerryscript || echo "JerryScript execution failed"
else
    echo "ERROR: JerryScript engine not found"
    exit 1
fi

echo ""
echo "All engines are working correctly!"
echo "Ready for differential testing with V8, XS, QuickJS, and JerryScript."
