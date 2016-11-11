DIR="$HOME"
FMT='TEST("%i", "%f");\\\n'
FMT_OSX="TEST(\"%i\", \"%f\");\\"
TYPE=d

echo "#define PRE \\"
if [[ "$(uname)" == "Linux" ]]; then
	find $DIR -type $TYPE -printf "$FMT"
else
	find $DIR -type $TYPE -print0 | xargs -0 stat -f "$FMT_OSX"
fi
