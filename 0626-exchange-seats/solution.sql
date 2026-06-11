
SELECT 
    id,
    CASE
        WHEN id % 2 = 0 THEN LAG(student) OVER(ORDER BY id)
        ELSE COALESCE(LEAD(student) OVER(ORDER BY id), student)
    END AS student
FROM Seat

# swap the names with the preceding record. This can be achieved using the SQL window function LAG(student) OVER (ORDER BY id) to retrieve the name from the line above.

-- For records with an odd ID, swap the names with the subsequent record. Use the window function LEAD(student) OVER (ORDER BY id) to fetch the name from the line below.
-- LEAD(student) OVER (ORDER BY id)
