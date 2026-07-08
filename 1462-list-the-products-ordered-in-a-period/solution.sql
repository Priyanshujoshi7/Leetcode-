# Write your MySQL query statement below
SELECT
    p.product_name AS product_name,
    SUM(o.unit) AS unit 
FROM Products as p
JOIN Orders as o
ON p.product_id = o.product_id
WHERE o.order_date like '2020-02-%'
GROUP BY o.product_id
HAVING unit>=100;
