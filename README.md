# linktree-cc

C++ Implementation of a LinkTree page.
Implemented mongodb using mongodbcxx driver.

# Docker

## Setup MongoDB for development environment

In order to use MongoDB and build the image we need MONGODB credentials.
Export some variables.

`export MONGODB_USER=<username>`
`export MONGODB_PASS=<password>`

## Open Docker and Build Image

`./build.sh`

The command will build the Docker image.
Then the command runs Docker and make.

## Open Docker and Run

`./run.sh`

Then run the crow server.

## Commit A Docker Image

Build docker
`docker ps`
Use ID from container
```
docker cp . {ID}:/usr/src/linktree-cc
docker commit {ID} linktree-cc:latest
```

## Build service image
Create a docker image to run the application.

`./deploy.sh`

# Heroku

## Heroku Login

`heroku login`

Heroku App:
https://<secret-inlet>.herokuapp.com
https://git.heroku.com/<secret-inlet>.git

## Push Container
```
heroky container:login
heroku container:push web -a <secret-inlet>
heroku container:release web -a <secret-inlet>
heroku open -a <secret-inlet>
```
