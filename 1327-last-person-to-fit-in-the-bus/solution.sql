# Write your MySQL query statement below
WITH ans AS (
    SELECT
        person_name,
        sum(weight) OVER(ORDER BY turn) AS Total_weight
    FROM Queue
)
SELECT
    person_name
FROM ans
WHERE Total_Weight = (SELECT max(total_weight) FROM ans where total_weight <=1000)
