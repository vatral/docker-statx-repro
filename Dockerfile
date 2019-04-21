FROM fedora:latest
RUN dnf update -y
RUN dnf install -y gcc glibc-devel make git
                  
