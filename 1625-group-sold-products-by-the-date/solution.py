import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:

    df = (activities.drop_duplicates()
                    .groupby('sell_date')['product'].agg(
                        num_sold = 'count',
                        products = list)
                    .reset_index())

    df.products = df.products.apply(lambda x: ','.join(sorted(x)))

    return df               
