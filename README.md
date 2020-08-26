# linktree-cc
C++ Implementation of a LinkTree page
# Docker 

## Open Docker and Build Image
Run image of docker
`./build.sh` 

Go to the package and build with CMake
`cd linktree-cc/build`
`cmake ..; make`

## Open Docker and Run
./run.sh

## Commit A Docker Image
Build docker
`docker ps`
Use ID from container
`docker cp . {ID}:/usr/src/linktree-cc`
`docker commit {ID} linktree-cc:latest`

## Build image
`docker build -t linktree-cc .`
# Heroku

## Heroku Login

`heroku login`

Heroku App:
https://<secret-inlet>.herokuapp.com
https://git.heroku.com/<secret-inlet>.git

## Push Container
`heroku container:push web -a <secret-inlet>`
`heroku container:release web -a <secret-inlet>`
`heroku open -a <secret-inlet>`

