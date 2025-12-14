# Write your MySQL query statement below
WITH Answer_table AS(
    SELECT
        w1.id
    FROM Weather w1
    JOIN Weather w2
    ON w1.recordDate = Date_ADD(w2.recordDate,INTERVAL 1 DAY)
    WHERE W1.temperature > W2.temperature
)
SELECT 
    id
FROM Answer_table;
