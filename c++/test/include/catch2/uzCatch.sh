DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

if [ ! -f "$DIR/catch.hpp" ]; then
    unzip "$DIR/catch.zip" -d $DIR
fi
