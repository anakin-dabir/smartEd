<p align="center">
  <img src="https://anakin-dabir.github.io/public/smartED.png" style='cursor:auto'/>
</p>
<p align="center">
<img src="https://img.shields.io/badge/react-v18.2-teal" />
<img src="https://img.shields.io/badge/express-v4.18.2-blue" />
<img src="https://img.shields.io/badge/mongoose-v7.0.4-darkgreen" />
</p>
<p align="center">
<img src="https://img.shields.io/badge/axios-v1.3.6-darkslateblue" />
<img src="https://img.shields.io/badge/daisyui-v2.51.5-lightseagreen" />
<img src="https://img.shields.io/badge/tailwindcss-v3.3.1-cadetblue" />

</p>

<hr />

### Introduction

SmartEd is a web application provides a comprehensive platform for instructors and students to interact and facilitate learning. It will allow individual instructors and educational institutes to create and manage their courses, upload course content, assignments. Students can access course material.

### Project Features

- Individual instructors and educational institutes can create an account and manage their profile. Similarly, students can register and create their profiles.
- Authentication and authorization is made secured using **JWT** authentication technique
- There's no need to remember password you can just log in via email and **OTP**
- Moreover there's two step verification via **OTP** sended to email of user whenever he tries to register or login
- Instructors can create courses and manage course details like course overview, course content, and assignments with deadlines. They can upload course content, including resources such as docs, PDFs, or images
- Students can access all course material once they are enrolled

## Run Locally

- Clone the project

```bash
  git clone https://github.com/anakin-dabir/smartEd.git
```

- Go to the project directory

```bash
  cd smartEd
```

- Install dependencies in both server and client folders

```bash
  cd client && yarn & cd api && yarn
```

<li>You need the following environment variables to add on server in .env file:
<ol>
<li>
<code>MONGO_DB</code> mongodb url</li>
<li>
<code>OPTIONS</code> config options for mongodb</li>
<li>
<code>SERVER</code> server side url</li>
<li>
<code>CLIENT</code> client side url</li>
<li>
<code>JWT_SECRET</code> secret token for JWT creation</li>
</ol>
</li>

- Start both client and server side servers separately by

```bash
  yarn dev
```

### API Endpoints

- **Authentication**
  | HTTP | Endpoints | Action |
  | ---------- | -------------------- | -------------------------------------- |
  | `POST` | /auth/getAll | To get all users |
  | `POST` | /auth/register | To generate otp |
  | `POST` | /auth/resendOTP | To request for regeneration of OTP |
  | `POST` | /auth/logout | To logout |
  | `POST` | /auth/getUserData | To get user data |
  | `POST` | /auth/updateProfile | To update user profile |

- **Courses**
  | HTTP | Endpoints | Action |
  | ---------- | -------------------- | -------------------------------------- |
  | `POST` | /course/getSAll | To retrieve all courses of instructors as student |
  | `POST` | /course/getAll | To retrieve all courses of current instructor |
  | `POST` | /course/getCourse | To retrieve data of current course |
  | `POST` | /addContent | To add content to the course |
  | `POST` | /course/addCourse | To add a new course |

### Mistakes

- **OTP**s are stored sessionally and not getting deleted taking the storage space, i wasn't educated about that at that time
