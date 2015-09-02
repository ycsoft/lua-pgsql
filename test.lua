
local pgsql = require("pgsql")
pgsql.sayHello()
local conn = pgsql.connectdb("hostaddr=127.0.0.1 dbname=fasp_yz user=postgres password=postgres")
local res = conn:exec("select * from b016")
print(res)