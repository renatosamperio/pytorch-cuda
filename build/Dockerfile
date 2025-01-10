
FROM renatosamperio/cuda-base

ARG IMG_PATH
ARG PYTORCH_CUDA_VERSION=cu124

USER root

# Solves issue with apt-get update fails due to NO_PUBKEY
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null \
    && apt update \
    && apt upgrade -y \
    && apt install -y \
        libegl1-mesa-dev \
        libxrandr2 \
        libxrandr2 \
        libxss1 \
        libxcursor1 \
        libxcomposite1 \
        libasound2-dev \
        libxi6 \
        libxtst6 \
        openssh-client \
    && apt autoremove -y

# install ollama manually
COPY $IMG_PATH/build/install-conda.sh /tmp/install-conda.sh
RUN /tmp/install-conda.sh \
    rm /tmp/install-conda.sh

ENV PATH=/opt/conda/bin:$PATH

RUN . /opt/conda/bin/activate \
    && conda config --append channels conda-forge \
    && /opt/conda/bin/python3 -m pip config set global.break-system-packages true \
    && /opt/conda/bin/pip3 install --index-url https://download.pytorch.org/whl/$PYTORCH_CUDA_VERSION \
        nvidia-cuda-cupti-cu12 \
        nvidia-cuda-nvrtc-cu12 \
        nvidia-nvtx-cu12 \
        requests \
        torch \
        torchvision \
        torchaudio 
RUN /opt/conda/bin/pip3 install --no-cache-dir \
        beautifulsoup4 \
        Flask \
        numpy \
        matplotlib \
        ollama \
        pandas \
        selenium \
        yfinance

# install armadillo for benchmark
RUN apt-get update -y \
    && apt install -y \
        libarmadillo-dev

# adding examples
COPY $IMG_PATH/src /opt/samples

# update and clean apt lists
RUN apt-get update -y \
    && apt upgrade -y \
    && apt autoremove -y \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
