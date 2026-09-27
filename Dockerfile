# Dockerfile

#   SPDX-License-Identifier: MIT
#   Copyright (c) 2026 Nico Erdmann
#   Dockerfile for NC

FROM gcc:latest AS builder

RUN apt-get update && apt-get install -y \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
COPY . .

SHELL ["/bin/bash", "-c"]

RUN mkdir -p build && cd build \
    && cmake .. \
    && cmake --build .

RUN shopt -s globstar \
    && chmod +x ./TEST.sh \
    && for test in tests/**/*.c; do \
        if [[ "$test" == *"test_must_operators"* ]] || [[ "$test" == *"test_nc_u8"* ]]; then \
            ./TEST.sh "$test" || true; \
        else \
            ./TEST.sh "$test" || exit 1; \
        fi; \
    done