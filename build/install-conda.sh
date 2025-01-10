SYS_ARCH="$(dpkg --print-architecture)"; 
case "$SYS_ARCH" in \
    arm64) export CONDA_ARCH='aarch64' ;; \
    amd64) export CONDA_ARCH='x86_64' ;; \
esac; 
echo "Installing ollama for '$SYS_ARCH' with '$CONDA_ARCH' conda architecture"

file_name=Miniconda3-latest-Linux-$CONDA_ARCH.sh
echo "Downloading $file_name..."
wget https://repo.anaconda.com/miniconda/$file_name 

if [ ! -f $file_name ]; then
    echo "File '$file_name' failed to download!" >&2
else 
    echo "File '$file_name' was found" >&1
fi

echo "Installing miniconda from '$file_name'..."
bash $file_name -b -p /opt/conda

echo "Removing '$file_name'..."
rm  -rf $file_name
