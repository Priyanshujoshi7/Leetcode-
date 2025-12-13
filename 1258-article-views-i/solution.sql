# Write your MySQL query statement below
WITH answertable AS(
    SELECT
        DISTINCT(author_id) AS id 
    FROM Views
    WHERE author_id = viewer_id
    ORDER BY id
)
SELECT
    id
FROM answertable;



