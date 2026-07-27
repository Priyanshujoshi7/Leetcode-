import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    grp = courses.groupby('class')['student'].size().reset_index()
    return grp[grp.student >= 5].iloc[:,[0]]
    
