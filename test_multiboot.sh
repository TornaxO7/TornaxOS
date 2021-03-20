#!/usr/bin/bash

echo "[MULTIBOOT TEST ON $1]"

if grub-file --is-x86-multiboot $1; then
    echo "CONFIRMED"
else
    echo "NOT MULTIBOOT"
fi
