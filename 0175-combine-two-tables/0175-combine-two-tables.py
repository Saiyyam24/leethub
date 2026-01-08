import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    val = person.merge(address,how='left',on='personId')
    val.drop(columns=['addressId','personId'],inplace=True)
    return val