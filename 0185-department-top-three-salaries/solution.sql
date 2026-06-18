# Write your MySQL query statement below
SELECT
    d.name AS department,
    e1.name AS employee,
    e1.salary AS Salary
FROM Employee e1
JOIN DEPARTMENT d
ON e1.departmentID = d.ID
WHERE 3 > (
    SELECT 
        COUNT(DISTINCT (e2.Salary))
        FROM Employee e2
        WHERE e2.Salary > e1.Salary
        AND e1.DepartmentId = e2.DepartmentID
)
