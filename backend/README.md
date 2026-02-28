# IEEE Conference Backend ⚙️

C++ backend API built with Drogon. Uses PostgreSQL for persistence and MinIO (S3-compatible) for object storage.

## ✅ Prerequisites

- C++ toolchain (gcc/clang)
- CMake (>= 3.15)
- Conan 2.x
- Docker (recommended for local Postgres + MinIO)

## 🧪 Local services (Postgres + MinIO)

```bash
docker compose up -d
```

Services:

- PostgreSQL: `localhost:5432` (db `ieee_conference_db`, user `postgres`, pass `postgres`)
- MinIO S3 API: `http://localhost:9000`
- MinIO Console: `http://localhost:9001`

## 🔧 Environment variables

The server loads env vars from a local `.env` file at startup.

```bash
cp .env.example .env
```

Common vars:

- `PORT` (defaults to `3000`)
- `JWT_SECRET` (required for token signing)
- `S3_ENDPOINT`, `S3_REGION`, `S3_ACCESS_KEY`, `S3_SECRET_KEY`, `S3_BUCKET`, `S3_USE_SSL`

## 🏗️ Build

```bash
conan profile detect --force
conan install . \
  --output-folder=build \
  --build=missing

cmake --preset conan-release
cmake --build --preset conan-release
```

## ▶️ Run

Important: the server loads `./config/config.json` using a **relative path**, so run it from inside this `backend/` directory:

```bash
./build/build/Release/IEEE_Conference_Backend
```

## 🐳 Container (optional)

There’s a production compose file to build/run the backend container:

```bash
docker compose -f docker-compose.prod.yml up --build
```