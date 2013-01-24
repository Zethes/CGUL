# Jatta uses spaces entirely
# Sometimes some tabs slip through
# This tool changes all tabs to spaces in the ../src directory
# On windows/mingw, run this in CMD: bash ./tabstospaces.sh
# On Unix-like, just ./tabstospaces.sh will do

# Exit on error
set -e

# Attempt to backup src
echo Backing up src directory to src_backup...
if [ -a "../src_backup" ]; then
    echo "ERROR: Failed to backup src (src_backup already exists)"
    exit 1
fi
cp -r ../src ../src_backup

TabsToSpacesRecursive()
{
    for d in *; do
        if [ -d $d ]; then
            (cd $d; TabsToSpacesRecursive)
        else
            sed -i "s/\t/    /g" $d
        fi
    done
}

(cd ../src; TabsToSpacesRecursive)