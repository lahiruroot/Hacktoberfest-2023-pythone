const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const app = express();

app.use(cors());
app.use(express.json());

const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'web_programming',
});

db.connect((err) => {
  if (err) {
    console.error('Connection failed: ' + err.message);
  } else {
    console.log('Connected to the database');
  }
});

app.listen(3001, () => {
  console.log('Server is running on port 3001');
});

// Your API routes and database queries will go here
