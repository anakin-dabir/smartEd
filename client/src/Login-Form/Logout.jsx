import React from 'react'
import { useContext } from 'react'
import { Context } from '../Provider'
import axios from 'axios'
import toast from 'react-hot-toast'
import { useNavigate } from 'react-router-dom'
import { useEffect } from 'react'

const Logout = () => {
    const navigate = useNavigate();
    const { setProvider } = useContext(Context);
    useEffect(()=>{
    (async () => {
        try {
            const response = await axios.post(`${import.meta.env.VITE_API}/auth/logout`, {}, { withCredentials: true });
            const { msg } = response.data;
            localStorage.clear();
            toast.success(msg);
            setProvider(prev => ({ ...prev, currentUser: {}, login: false, allUsers: [] }));
            // navigate('/');
        }
        catch (err) {
            toast.error(err.response.data.msg);
        }
    })()
},[])
    
    return (
        <></>
            
        
    )
}

export default Logout