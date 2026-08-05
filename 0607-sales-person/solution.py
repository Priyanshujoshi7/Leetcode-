import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:

    company = company[company.name == 'RED']
    orders = orders[orders.com_id.isin(company.com_id)]

    sales_person = sales_person[~sales_person.sales_id.isin(orders.sales_id)]
    return sales_person.iloc[:,[1]]
