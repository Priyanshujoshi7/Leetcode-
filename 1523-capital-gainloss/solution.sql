SELECT 
    stock_name, 
    sum(case when operation = 'buy' then -price else price end) as capital_gain_loss 
FROM Stocks 
GROUP BY stock_name
