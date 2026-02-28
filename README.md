# IEEE Conference / IEEE IAS SBC – NIT Patna

Official repository for the IEEE IAS Student Branch Chapter (NIT Patna).

## ✨ What’s in this repo

- 🖥️ **Frontend**: React + Vite + TypeScript + Tailwind (in `frontend/`)
- ⚙️ **Backend**: C++ (Drogon) API with PostgreSQL + MinIO (in `backend/`)
- 📚 **Docs / Infra**: currently empty placeholders (`docs/`, `infra/`)

## 🧩 Tech stack

- Frontend: React, Vite, TypeScript, TailwindCSS
- Backend: Drogon, Conan, CMake, AWS SDK (S3)
- Services: PostgreSQL (DB), MinIO (S3-compatible storage)

## 🚀 Quick start (local dev)

### 1) Start backend dependencies (Postgres + MinIO)

```bash
cd backend
docker compose up -d
```

This brings up:

- 🗄️ PostgreSQL: `localhost:5432` (db `ieee_conference_db`, user `postgres`, pass `postgres`)
- 🪣 MinIO (S3 API): `http://localhost:9000`
- 🧭 MinIO Console: `http://localhost:9001`

MinIO defaults (from `backend/docker-compose.yml`):

- Access key: `suryansh`
- Secret key: `suryansh`

### 2) Configure backend env

The backend loads environment variables from a local `.env` file (read from the current working directory).

```bash
cd backend
cp .env.example .env
```

Typical variables:

- `PORT` (default `3000`)
- `JWT_SECRET` (required for auth tokens)
- `S3_ENDPOINT`, `S3_REGION`, `S3_ACCESS_KEY`, `S3_SECRET_KEY`, `S3_BUCKET`, `S3_USE_SSL`

### 3) Build + run the backend

Prereqs:

- C++ toolchain
- CMake (>= 3.15)
- Conan 2.x

Build:

```bash
cd backend
conan profile detect --force
conan install . --output-folder=build --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
```

Run (important: run from inside `backend/` because config is loaded via a relative path `./config/config.json`):

```bash
cd backend
./build/build/Release/IEEE_Conference_Backend
```

### 4) Run the frontend

Prereqs:

- Node.js (LTS recommended)
- npm

```bash
cd frontend
npm install
npm run dev
```

Vite will print the local dev URL (typically `http://localhost:5173`).

## 🔌 API (backend)

Base URL (default): `http://localhost:3000`

- ✅ Health check: `GET /health`
- 🔐 Users (base: `/api/v1/users`)
	- `POST /api/v1/users/login`
	- `POST /api/v1/users/signup`
	- `GET /api/v1/users?page=1&limit=10`
	- `GET /api/v1/users/profile?id=123`
	- `PUT /api/v1/users?id=123` (requires `Authorization: Bearer <token>`)
	- `DELETE /api/v1/users/{id}` (requires `Authorization: Bearer <token>`)

## 🗂️ Repository structure

```text
.
├── backend/                  # Drogon C++ API + docker services
│   ├── docker-compose.yml     # Postgres + MinIO for local dev
│   ├── docker-compose.prod.yml# Backend container (app-only)
│   ├── config/config.json     # DB client config (defaults to 127.0.0.1:5432)
│   ├── sql/                   # DB init scripts (e.g., users table)
│   └── src/                   # controllers/filters/services + main
├── frontend/                 # React + Vite + Tailwind site
├── docs/                     # placeholder
├── infra/                    # placeholder
└── docker-compose.yml        # currently empty placeholder
```

## 🧰 Notes & troubleshooting

- If the backend can’t find its config, make sure you started it from `backend/`.
- If DB connection fails, check `backend/config/config.json` and that Postgres is running on `localhost:5432`.
- MinIO is started by `backend/docker-compose.yml`; update `backend/.env` if you change MinIO credentials/ports.

## 📄 License

See [LICENSE](LICENSE).