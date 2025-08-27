FROM gcc:latest
WORKDIR /app
COPY . .
RUN g++ -o myapp main.cpp
CMD ["./myapp"]
