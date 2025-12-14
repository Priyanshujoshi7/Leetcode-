# Write your MySQL query statement below
WITH answer_table AS (
    SELECT
        eu.unique_id,
        e.name
    FROM Employees e
    LEFT JOIN EmployeeUNI eu
        ON e.id = eu.id
)
SELECT unique_id, name
FROM answer_table;

