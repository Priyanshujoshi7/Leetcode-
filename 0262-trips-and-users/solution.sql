WITH valid_trips AS (
    SELECT
        t.request_at AS Day,
        t.status
    FROM Trips t
    JOIN Users c
        ON t.client_id = c.users_id
        AND c.banned = 'No'
    JOIN Users d
        ON t.driver_id = d.users_id
        AND d.banned = 'No'
    WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
),
daily AS (
    SELECT
        Day,
        COUNT(*) OVER (PARTITION BY Day) AS total_trips,
        SUM(
            CASE
                WHEN status IN ('cancelled_by_client', 'cancelled_by_driver')
                THEN 1
                ELSE 0
            END
        ) OVER (PARTITION BY Day) AS cancelled_trips
    FROM valid_trips
)
SELECT DISTINCT
    Day,
    ROUND(cancelled_trips / total_trips, 2) AS `Cancellation Rate`
FROM daily;
