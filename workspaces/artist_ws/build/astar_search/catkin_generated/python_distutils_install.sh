#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/arham/catkin_ws/src/astar_search"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/arham/catkin_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/arham/catkin_ws/install/lib/python3/dist-packages:/home/arham/catkin_ws/build/astar_search/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/arham/catkin_ws/build/astar_search" \
    "/usr/bin/python3" \
    "/home/arham/catkin_ws/src/astar_search/setup.py" \
     \
    build --build-base "/home/arham/catkin_ws/build/astar_search" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/arham/catkin_ws/install" --install-scripts="/home/arham/catkin_ws/install/bin"
