import {useState, useEffect, useContext} from 'react'
import { NavLink } from 'react-router-dom';
import { Context } from '../Provider';
import { Link } from 'react-router-dom';
import Logout from '../Login-Form/Logout';
import MyAwesomeThemeComponent from '../ThemeToggle/toggle';
const NavBar = () => {
const {provider} = useContext(Context);
    const [prevScrollPos, setPrevScrollPos] = useState(0);
    const [visible, setVisible] = useState(true);
    const [top, setTop] = useState(true);
    const handleScroll = () => {
        const currentScrollPos = window.pageYOffset;
        if (currentScrollPos === 0) {
            setTop(true);
        }
        else {
            setTop(false);
        }
        setVisible(prevScrollPos > currentScrollPos || currentScrollPos < 10);
        setPrevScrollPos(currentScrollPos);
    }
    useEffect(() => {
        window.addEventListener("scroll", handleScroll);
        return () => window.removeEventListener("scroll", handleScroll);
    }, [prevScrollPos, visible, handleScroll]);

    return (
        <div className={`fixed w-full z-50 ${top ? 'bg-base-300' : 'backdrop-blur-md bg-neutral bg-opacity-10 transition duration-300 ease-in-out'}  shadow-md   ${visible ? "top-0" : "-top-full"}`}>
            <div className="navbar px-3 container mx-auto lg:max-w-screen-xl">
                <div className="text-2xl text-primary underline font-bold navbar-start">
SmartED
             </div>

<div className="navbar-center"><MyAwesomeThemeComponent/></div>

                <div className="navbar-end">
                    <ul className="menu menu-horizontal gap-1 rounded-box">
                        

                        <div className="dropdown ml-3">
              <label tabIndex={0} className="btn btn-ghost btn-circle avatar avatar-online">
                <div className="w-12 bg-primary rounded-full avatar-online">
                     <img src={`http://localhost:9999/photos/${provider.currentUser.img}`}/>
                </div>
              </label>
              <ul tabIndex={0} className="menu dropdown-content mt-3 p-2 shadow-lg bg-primary-content text-base-content rounded-box w-52">
                <li>
                  <Link to={`/profile/${provider.currentUser._id}`}>
                    Profile
                  </Link>
                </li>
                <li><Link to='/logout'>Logout</Link></li>
              </ul>
            </div>


                    </ul>
                </div>
            </div>
        </div>
    )



}
export default NavBar;