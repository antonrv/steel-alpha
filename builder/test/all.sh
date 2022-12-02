BUILDDIR=$1

EXRUN=". test/all.sh build_test"

if [ -z "$BUILDDIR" ]
then
      echo "Arguments: [BUILD DIR]. Example: $EXRUN"
      return 0
fi


# Compile all
bld steelbld-parser-test steelbld-i steelbld-it steelbld-itg steelbld-itgs steelbld-itgsc steelbld-itgscl

# Test parser
steelbld-parser-test

# Test builder
steelbld-itg -builder-test=all -build=$BUILDDIR -steel=$STEELPATH

