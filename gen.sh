DIR="$HOME"
FMT="\tTEST(\"%i\", \"%f\"); \\\n"
FMT_OSX="TEST(\"%i\", \"%f\"); \\"

echo "#define PRE \\"
if [[ "$(uname)" == "Linux" ]]; then
	find $DIR -type d -printf "$FMT"
else
	find $DIR -type d -print0 | xargs -0 stat -f "$FMT_OSX"
fi
