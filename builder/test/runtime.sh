BUILDDIR=$1
STEELPATH=$2

if [ -z "$BUILDDIR" ]
then
      echo "Arguments: [BUILD DIR] [STEELPATH]"
      return 0
fi

STEELPATH="[LLVM-PROJECT-DIR]/clang-tools-extra/steel"

RT_TESTS=('task_create' 'wrap_and_exec' 'exec_reimplement'  'work_queue' 'dep_0d' 'dep_1d_mesh_direct' 'dep_2d_mesh_direct' 'dep_3d_mesh_direct')
 
echo "Testing Runtime tests on '$STEELPATH/test', building on '$BUILDDIR'"

for RT_TEST in "${RT_TESTS[@]}"
do
  echo "Compiling $RT_TEST"
  steelbld-itgscl -runtime-test=$RT_TEST -build=$BUILDDIR -steel=$STEELPATH -plat=platname

  echo "Running $RT_TEST"
  echo "$BUILDDIR/runtime/test/$RT_TEST/run/main.rn"
  $BUILDDIR/runtime/test/$RT_TEST/run/main.rn
done
