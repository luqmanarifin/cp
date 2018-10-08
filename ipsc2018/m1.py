import requests as rq
import time

cookies = {
    'ipsc2018ann': '2',
    'ipscsessid': 'c0932a249f01baf21e7dc3f0d80469a7b433ec28'
}
url = 'https://ipsc.ksp.sk/2018/real/problems/m_api'

refresh_data = {
    'action': 'refresh'
}

while True:
    resp = rq.post(url, cookies=cookies, data=refresh_data).json()
    print('Refreshed')
    for cust in resp['active_customers']:
        print('Submitting data for customer {}'.format(cust['customer_id']))
        submit_data = {
            'action': 'submit',
            'customer_id': cust['customer_id'],
        }
        if cust['text'] == 'HELLO I WOULD LIKE TO ORDER FOOD ITEM var1.':
            submit_data['answer'] = cust['var1']
        elif cust['text'] == 'OLLEH, I MA A BOTOR TAHT SKLAT SDRAWKCAB. EVIG EM DOOF var1 ESAELP.':
            submit_data['answer'] = cust['var1'][::-1]
        elif cust['text'] == 'GOOD DAY COUGH GIVE ME FOOD var1 COUGH COUGH COUGH. PARDON ME, THAT WAS A BUFFER OVERFLOW. I WANTED TO SAY THE FIRST 110 DIGITS OF THAT, PLEASE IGNORE THE REST.':
            submit_data['answer'] = cust['var1'][:6]
        else:
            print('Message not found: {}'.format(cust['text']))
            continue

        submit_resp = rq.post(url, cookies=cookies, data=submit_data).json()
        print(submit_resp['result'])

    time.sleep(10)
