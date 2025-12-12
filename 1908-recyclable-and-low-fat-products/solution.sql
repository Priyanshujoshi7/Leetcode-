# Write your MySQL query statement below
WITH Answer_table AS (
    SELECT
        product_id,
        low_fats,
        recyclable
    FROM products
    Where low_fats = 'Y'
    AND recyclable = 'Y'
)
SELECT
    product_id
FROM Answer_table;
