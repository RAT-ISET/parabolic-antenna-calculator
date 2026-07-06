FROM archlinux:latest
LABEL authors="Rangeset"

ENTRYPOINT ["top", "-b"]

RUN pacman -Syu --noconfirm && pacman -S --noconfirm base-devel && useradd -m builder

USER builder
WORKDIR /home/builder
