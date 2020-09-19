. common.sh

if [[ -n "`docker images | grep ${PREFIX}-cc`" ]];
then 
  docker -t ${PREFIX}-cc .
fi

echo "docker run --rm -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/${PREFIX}/build -it bbox:latest /usr/bin/make $@"
docker run --rm -v ${HOST_PATH}:${TARGET_PATH}  -w ${TARGET_PATH}/${PREFIX}/build -it bbox:latest /usr/bin/make $@
