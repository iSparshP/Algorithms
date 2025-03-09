import pandas as pd

def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:
    total_users=users["user_id"].nunique()
    registered_group=(register.groupby("contest_id")["user_id"]
    .nunique()
    .reset_index(name="count_unique_users"))
    registered_group["percentage"]=(
        registered_group["count_unique_users"] / total_users
    ) * 100
    registered_group["percentage"] = registered_group["percentage"].round(2)
    registered_group = registered_group.sort_values(
    by=["percentage", "contest_id"], ascending=[False, True])
    final_df = registered_group[["contest_id", "percentage"]]
    return final_df




# percent of the users registed in each contest
# rounded to two decimals
# descending order by percentage
# if tie order by contest_id in ascending order