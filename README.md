# IEEE Conference

Official repository for the IEEE Conference website, including backend, frontend, infrastructure, and documentation.

## Current Status

- **Backend**: C++ (Drogon) service with PostgreSQL configuration.
- **Frontend / Infra / Docs**: Placeholders for future development.

## Prerequisites

Backend development requires:

- C++ toolchain
- CMake (>= 3.15)
- Conan 2.x
- Docker (recommended, for running PostgreSQL locally)

## Quickstart (Backend)

### 1) Start PostgreSQL (Docker)

From the backend folder, start the DB container:

```bash
cd backend
docker compose up -d
```

This uses the default credentials in `backend/docker-compose.yml`:

- DB: `ieee_conference_db`
- User: `postgres`
- Password: `postgres`
- Host port: `5432`

### 2) Build the backend

```bash
cd backend
conan profile detect --force
conan install . --output-folder=build --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
```

### 3) Configure environment

The backend loads environment variables from `.env` at startup.

- Copy and edit as needed:

```bash
cd backend
cp .env.example .env
```

Currently supported:

- `PORT` (defaults to `3000`)

### 4) Run the backend

Important: the server loads `./config/config.json` as a **relative** path, so run it from inside the `backend/` directory.

```bash
cd backend
./build/build/Release/IEEE_Conference_Backend
```

You should see a log like:

```
server is listening on port:3000
```

## Configuration

- Server port: `backend/.env` (`PORT`)
- Database connection: `backend/config/config.json`

By default, the database configuration points to:

- host: `127.0.0.1`
- port: `5432`

If you run PostgreSQL differently (e.g., remote DB), update `backend/config/config.json`.

## Repository Structure

```text
.
├── backend/                 # Drogon C++ server (active)
│   ├── src/                 # main.cc + app folders (currently mostly empty)
│   ├── config/config.json   # Drogon + DB config
│   ├── .env.example         # Example env
│   └── docker-compose.yml   # Local Postgres
├── frontend/                # (empty placeholder)
├── infra/                   # (empty placeholder)
└── docs/                    # (empty placeholder)
```

## Notes

- The root-level `docker-compose.yml` and `app.env` are currently empty placeholders.
- `backend/Dockerfile` is currently empty; containerizing the backend is not wired up yet.