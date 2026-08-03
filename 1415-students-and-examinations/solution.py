import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    result = pd.merge(
        left=pd.merge(
            students,
            subjects,
            how='cross'
        ).sort_values(
            by=['student_id', 'subject_name']
        ),
        right=examinations.groupby(
            ['student_id', 'subject_name']
        ).agg(
            attended_exams=('subject_name', 'count')
        ).reset_index(),
        how='left',
        on=['student_id', 'subject_name']
    )

    result['attended_exams'] = result['attended_exams'].fillna(0).astype(int)

    return result[
        ['student_id', 'student_name', 'subject_name', 'attended_exams']
    ]
