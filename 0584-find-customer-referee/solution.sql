# Write your MySQL query statement below
WITH answer_table AS(
    SELECT
        name 
    FROM Customer
    WHERE referee_id <> 2
    OR referee_id IS NULL
)

SELECT 
    name
FROM answer_table;
