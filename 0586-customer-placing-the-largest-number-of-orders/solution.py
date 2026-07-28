import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:

    orders['counts'] = orders.groupby('customer_number').transform('size')

    return orders.sort_values(by = ['counts']).tail(1).iloc[:,[1]]
