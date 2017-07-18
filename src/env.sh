
home_3rd=~/3rd

if test -d /llj/3rd ; then
   home_3rd=/llj/3rd
fi

home_boost=$home_3rd/boost
home_zeusing=$home_3rd/ZeusingApi_20150331

export LD_LIBRARY_PATH=$home_boost/lib:$home_zeusing


