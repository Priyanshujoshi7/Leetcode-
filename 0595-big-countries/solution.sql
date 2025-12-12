# Write your MySQL query statement below
WITH Answer_table AS(
    SELECT
        name,
        population,
        area
    FROM World
    WHERE area >= 3000000
    OR population >= 25000000
)

SELECT
    name,
    population,
    area
FROM Answer_table;

