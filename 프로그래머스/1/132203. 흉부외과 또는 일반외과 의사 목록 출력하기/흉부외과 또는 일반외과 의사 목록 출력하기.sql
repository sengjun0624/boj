-- 코드를 입력하세요
SELECT DR_NAME,DR_ID,MCDP_CD,DATE_FORMAT(hire_ymd,'%Y-%m-%d')as hire_ymd FROM DOCTOR WHERE MCDP_CD='cs' OR mcdp_cd='gs' order by hire_ymd desc ,dr_name

