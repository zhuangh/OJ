import asyncio
import math
import time
import requests
from concurrent.futures import ThreadPoolExecutor
import aiohttp
# http://www.dongwm.com/archives/%E4%BD%BF%E7%94%A8Python%E8%BF%9B%E8%A1%8C%E5%B9%B6%E5%8F%91%E7%BC%96%E7%A8%8B-asyncio%E7%AF%87/
NUMBERS = range(12)
URL = 'http://httpbin.org/get?a={}'

async def fetch_async(a):
    async with aiohttp.request('GET', URL.format(a)) as r:
        data = await r.json() # Need keywords await. r.json waits for I/O（a network request），switch to other task, then back
    return a, data['args']['a']

def sub_loop(numbers):
    loop = asyncio.new_event_loop() # create event loop
    asyncio.set_event_loop(loop) # loop to 
    tasks = [fetch_async(num) for num in numbers]
    results = loop.run_until_complete(asyncio.gather(*tasks)) # gather collects the async task results.
    for num, result in results:
        print('fetch({}) = {}'.format(num, result))

async def run(executor, numbers):
    await asyncio.get_event_loop().run_in_executor(executor, sub_loop, numbers)

def chunks(l, size):
    n = math.ceil(len(l) / size)
    for i in range(0, len(l), n):
        yield l[i:i + n]                                        

start = time.time()
executor = ThreadPoolExecutor(3)
event_loop = asyncio.get_event_loop()
tasks = [run(executor, chunked) for chunked in chunks(NUMBERS, 3)]
results = event_loop.run_until_complete(asyncio.gather(*tasks))
print('Use asyncio+aiohttp+ThreadPoolExecutor cost: {}'.format(time.time() - start))
