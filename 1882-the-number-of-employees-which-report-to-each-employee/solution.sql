SELECT 
    e1.employee_id,
    e1.name,count(*) as reports_count, 
    round(avg(e2.age)) as average_age 
FROM Employees as e1
JOIN Employees as e2
ON e1.employee_id = e2.reports_to 
GROUP BY employee_id
ORDER BY employee_id;
