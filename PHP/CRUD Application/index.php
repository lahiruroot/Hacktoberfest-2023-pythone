import React, { useState, useEffect } from 'react';

function EmployeeTable() {
  const [employeeData, setEmployeeData] = useState([]);

  useEffect(() => {
    // Fetch data from your API or server here
    // Example:
    fetch('/api/employee')
      .then((response) => response.json())
      .then((data) => setEmployeeData(data))
      .catch((error) => console.error('Error fetching data:', error));
  }, []);

  return (
    <div>
      <h1>Assignment</h1>
      <table>
        <thead>
          <tr>
            <th>Id</th>
            <th>First Name</th>
            <th>Last Name</th>
            <th>E-mail</th>
            <th>Address</th>
            <th>Number</th>
            <th>Delete</th>
            <th>Update</th>
          </tr>
        </thead>
        <tbody>
          {employeeData.map((employee) => (
            <tr key={employee.id}>
              <td>{employee.id}</td>
              <td>{employee.first_name}</td>
              <td>{employee.last_name}</td>
              <td>{employee.email}</td>
              <td>{employee.address}</td>
              <td>{employee.number}</td>
              <td>
                <a
                  href={`delete.php?id=${employee.id}`}
                  onClick={() => {
                    const confirmDelete = window.confirm('Are you sure?');
                    if (!confirmDelete) {
                      return false;
                    }
                  }}
                >
                  Delete
                </a>
              </td>
              <td>
                <a
                  href={`edit.php?id=${employee.id}`}
                  onClick={() => {
                    const confirmUpdate = window.confirm('Are you sure?');
                    if (!confirmUpdate) {
                      return false;
                    }
                  }}
                >
                  Update
                </a>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
      <h3>
        <a href="insert.php">Add new record</a>
      </h3>
    </div>
  );
}

export default EmployeeTable;
