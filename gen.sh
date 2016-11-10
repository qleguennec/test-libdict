DIR="$HOME"
FMT='TEST("%i", "%f");\\\n'
FMT_OSX="TEST(\"%i\", \"%f\");\\"

echo "#define PRE \\"
if [[ "$(uname)" == "Linux" ]]; then
	find $DIR -printf "$FMT"
else
	find $DIR -print0 | xargs -0 stat -f "$FMT_OSX"
fi
