
# CampusGuard
[description]


## Authors

- [u24916031 - Jamie King](https://github.com/u24916031-Jamie)
- [uXXXXXXXX - Nare Maela](https://github.com/N-Githu)
- [u25176502 - Stephen Odhiambo](https://github.com/u25176502-commits)


## Run Locally

Clone the project

```bash
git clone https://github.com/u24916031-Jamie/COS214PA5
```

Go to the project directory

```bash
cd COS214PA5
```

Build Docker Image
```bash
docker compose up --build
```

Run Docker
```bash
docker run -it cos214pa5-app
```

Compile

```bash
make
```

Run

```bash
./campusGuard
```

Run valgrind
```bash
valgrind ./campusGuard
```


Run gdb
```bash
make test
make runtest
```