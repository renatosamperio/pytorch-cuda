# How to build it?
To build use the following command:
```
docker buildx build  -t renatosamperio/pytorch-cuda:latest --platform linux/amd64,linux/arm64 --build-arg IMG_PATH=pytorch-cuda  -f $1/build/Dockerfile . 
```

# How to load it?
To use it locally use the following command:
```
docker buildx build  -t renatosamperio/pytorch-cuda:latest --build-arg IMG_PATH=pytorch-cuda  -f $1/build/Dockerfile . --load 
```

# How to push it?
To use it locally use the following command:
```
docker buildx build  -t renatosamperio/pytorch-cuda:latest --platform linux/amd64,linux/arm64 --build-arg IMG_PATH=pytorch-cuda  -f $1/build/Dockerfile . --push
```