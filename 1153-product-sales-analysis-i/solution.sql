# Write your MySQL query statement below
WITH Answer_table AS(
    SELECT
        p.product_name AS product_name,
        s.year AS year,
        s.price as price
    FROM Sales AS s
    JOIN Product AS p
    ON s.product_id = p.product_id
)
SELECT
    product_name,
    year,
    price
FROM Answer_table;
